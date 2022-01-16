# AtCoder_submissions

****
Author: BigTree777
Date: 2022/01/06
****

## Requirement Definition

|Purpose|Get submissions from AtCoder and save in local directory|
|:-:|:-:|
|Platform|Windows|
|Interface|CLI|
|Language|Python|
|Library|requests, selenium, chromedriver_binary, sleep, re, os|
|Reference|[AtCoderの提出コードを取得し、GitHubにプッシュする](https://zenn.dev/tishii2479/articles/6b381fb86e0369)|
|Deadline|2022/01/16|

## Basic Design

1. Run AtCoder_submissions.py

```python
python AtCoder_submissions.py
```

2. Input user_ID of AtCoder
3. If you see the message **Finish!** on the standard output, you are done

## Work Flow

1. **get_submissions**
    Make a function to get submissions from AtCoder (30[min])
   1-1. Learn about requests (10[min])
   1-2. Learn about AtCoder API (10[min])
2. **collect_latest_submissions**
    Make a function to collect the most rescent submission for each contest (30[min])
3. **save_submissions**
    Make a function to save submissions in local directory (30[min])

## Detailed Design

### File

- submissions.py: main file

### Variable

||Detail|
|:-:|:-:|
|user_ID|user_ID in AtCoder|
|unix_second|constant 0|
|api_path|path to AtCoder API|
|||

### Function

||Input|Output|Local Variable|Detail|
|:-:|:-:|:-:|:-:|:-:|
|get_submissions|api_path, user_ID|submissions|api_url: api_path + user_ID|Get submissions|
|collect_latest_submissions|submissions|result|
|save_submissions|submissions||
|main|||

## Code Check

- [ ] import os
- [ ] import re
- [ ] import json
- [ ] import requests
- [ ] import chromedriver_binary
- [ ] from selenium import webdriver
- [ ] from time import sleep
- [ ] user_ID
- [ ] api_path
- [ ] get_submissions(user_ID, api_path)
- [ ] collect_latest_submissions(submissions)
- [ ] save_submissions(submissions)
- [ ] main

## Test

- [ ] Recieve input correctly

> print(user_ID)

- [ ] [Check URL](https://qiita.com/seigot/items/534ca3089d217200a1d6)
- [ ] Get submissions correctly(get_submissions)

> print(submissions)

- [ ] Summarize by contests correctly

> print(result)

- [ ] Create submission directory correctly
- [ ] Setting file path correctly
- [ ] Skip saved file
- [ ] Get code correctly
- [ ] Save code correctly
