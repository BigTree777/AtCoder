# Deque: 両端キューのこと
# popとappendが高速 -> 要素の追加や削除が多い時に便利
# listは固定長の操作に特化している -> 両端以外の要素にアクセスする時に便利
# https://note.nkmk.me/python-collections-deque/
from collections import deque

if __name__=="__main__":
    a, N = map(int, input().split())

    M = 1
    while M <= N:
        M *= 10 # 上限設定

    d = [-1] * M # インデックスが黒板の値，要素がカウント -> d[N]が答え
    d[1] = 0

    Q = deque() # 黒板の値
    Q.append(1)

    while len(Q): # 候補がなくなったら終了
        c = Q.popleft() # 現在の黒板の値
        dc = d[c] # 現在の値に何回で到達したか

        # 操作1: a倍
        op1 = a * c
        if op1<M and d[op1]==-1: # Mより小さく，d[op1]に初めて到達
            d[op1] = dc + 1 # カウントを増やす
            Q.append(op1) # 黒板がとりうる値として追加

        # 操作2: 下一桁と上一桁を入れ替え
        if c>=10 and c%10!=0: # 2桁以上で10の倍数でない
            s = str(c) # 文字列化
            op2 = int(s[-1] + s[:-1]) # 入れ替え
            if op2<M and d[op2]==-1: # Mより小さく，d[op2]に初めて到達
                d[op2] = dc + 1 # カウントを増やす
                Q.append(op2) # 黒板がとりうる値として追加

    print(d[N])
