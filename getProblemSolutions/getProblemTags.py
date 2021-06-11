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
        problemRating  = 0
        tags = set()
        if 'rating' in problem:
            problemRating = problem['rating']
        if 'tags' in problem:
            tags = problem['tags']
        temp_dic = {}
        temp_dic['tags'] = tags
        temp_dic['rating'] = problemRating
        dic[problemName] = temp_dic
    return dic
dic = getProblemTags()
c = 0
for i in dic:
    c += 1
    if c > 5:
        break
    print(i)
    print(dic[i]['tags'])
    print(dic[i]['rating'])