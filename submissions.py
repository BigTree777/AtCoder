#**************************************************

# Author: BigTree777
# Date: 2022/01/16
#**************************************************

# Library
import os
import re
import json
import html
import requests
import chromedriver_binary
from time import sleep
from termcolor import cprint
from selenium import webdriver

# Global variable
api_path:str = "https://kenkoooo.com/atcoder/atcoder-api/v3/user/submissions?user="
unix_second:str = 0

def get_submissions(api_url:str) -> json:
    ''' Access api_url and obtain the information using GET method.
        Then, the information is converted to json format.
    '''
    response = requests.get(api_url)

    # # debug
    # cprint("status code", "yellow")
    # print(response.status_code)

    submissions = response.json()

    # # debug
    # cprint("submissions", "yellow")
    # print(submissions)

    return submissions

def collect_latest_submissions(submissions:json) -> json:
    ''' Collect the latest submissions for each problem and summarize submissions by contest.
    '''
    # Sort by oldest to newest
    sorted_sub = sorted(submissions, key=lambda x: x["id"])

    # Collect the latest submissions(target AC only)
    ac_sub = {}
    for sub in sorted_sub:
        if sub["result"] != "AC": continue
        ac_sub[sub["problem_id"]] = sub

    # # debug
    # cprint("ac_sub", "yellow")
    # print(ac_sub)

    # Summarize by contest
    collected_sub = {}
    for sub in ac_sub.values():
        if not sub["contest_id"] in collected_sub.keys():
            collected_sub[sub["contest_id"]] = {}
        collected_sub[sub["contest_id"]][sub["problem_id"]] = sub

    # # debug
    # cprint("collected_sub", "yellow")
    # print(collected_sub)

    return collected_sub

def save_submissions(collected_sub:json) -> bool:
    ''' Save submissions by each contests
    '''
    # Make submissions directory
    sub_dir = "submissions"
    if not os.path.exists(sub_dir):
        os.mkdir(sub_dir)
    
    # Set ChromeDriver
    driver = webdriver.Chrome()

    for contest_id in collected_sub.keys():
        # Make contest directory
        contest_dir = os.path.join(sub_dir, contest_id)
        if not os.path.exists(contest_dir):
            os.mkdir(contest_dir)

        # Get problem id list
        problem_id_list = collected_sub[contest_id].keys()

        for problem_id in problem_id_list:
            # Make file path
            file_path = os.path.join(contest_dir, problem_id)

            # Set extension
            if "C++" in collected_sub[contest_id][problem_id]["language"]:
                file_path += ".cpp"
            elif "Python" in collected_sub[contest_id][problem_id]["language"]:
                file_path += ".py"
            
            # # debug
            # print("sub_dir: ", sub_dir)
            # print("contest_dir: ", contest_dir)
            # print("file_path: ", file_path)

            # Skip saved problem
            if os.path.exists(file_path): continue

            # Access AtCoder
            sub_url = "https://atcoder.jp/contests/" + contest_id + "/submissions/" + str(collected_sub[contest_id][problem_id]["id"])
            driver.get(sub_url)

            # # debug
            # cprint("sub_url status code", "yellow")
            # print(requests.get(api_url).status_code)

            # Get submission code
            sub_code = driver.find_element_by_id("submission-code") 

            # Format code
            inner_html = sub_code.get_attribute('innerHTML')
            # '^' means 'not' 
            # '.*?' means 'as short a text as possible'
            list_items = re.findall(r'<li[^>]*>.*?</li>', inner_html)
            lines = []
            for li in list_items:
                line1 = re.sub(r'<[^>]+>', '', li)
                line2 = re.sub(r'&nbsp;', '', line1)
                line3 = html.unescape(line2)
                lines.append(line3 + "\n")
            # Convert list to string
            sub_code_text = ''.join(lines)

            # Save
            with open(file_path, 'w') as f:
                f.write(sub_code_text)

            # Sleep
            sleep(3)
    
    # Quit
    driver.quit()
    # Return
    return True

# Main
if __name__=="__main__":
    print("Please input your AtCoder user ID")
    user_ID = input()
    api_url = api_path + user_ID + "&from_second=" + str(unix_second)
    submissions = get_submissions(api_url)
    collected_sub = collect_latest_submissions(submissions)
    if save_submissions(collected_sub):
        cprint("Finish!", "green")
