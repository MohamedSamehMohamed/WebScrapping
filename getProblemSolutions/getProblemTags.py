import requests

def request(url):
    return requests.get(url).json()

def get_problem_tags():
    dic = {}
    try:
        url = "https://codeforces.com/api/problemset.problems"
        res = request(url)['result']['problems']

        for problem in res:
            problem_name = str(problem['contestId']) + str(problem['index'])
            problem_rating  = 0
            tags = set()
            if 'rating' in problem:
                problem_rating = problem['rating']
            if 'tags' in problem:
                tags = problem['tags']
            temp_dic = {'tags': tags, 'rating': problem_rating}
            dic[problem_name] = temp_dic
        return dic
    except Exception as e:
        print ('can\'t get problem tags')
        print(e)
        return dic
