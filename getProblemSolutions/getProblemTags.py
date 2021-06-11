import requests

def request(url):
    return requests.get(url).json()

def getProblemTags():
    dic = {}
    url = "https://codeforces.com/api/problemset.problems"
    json = request(url)
    res = json['result']
    res = res['problems']
    for problem in res:
        problemName = str(problem['contestId']) + str(problem['index'])
        try:
            dic[problemName] = problem['tags']
        except:
            pass
    return dic
