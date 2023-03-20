from git import Repo

PATH_OF_GIT_REPO = r'E:\ProgrammingLangueTraining\python\WebScrapping\.git'

def git_push(file_name, commit_massage):
    try:
        repo = Repo(PATH_OF_GIT_REPO)
        repo.index.add(file_name)
        repo.index.commit(commit_massage)
        origin = repo.remote(name='origin')
        origin.push()
    except Exception as e:
        print (e)
        print('Some error occured while pushing the code')
