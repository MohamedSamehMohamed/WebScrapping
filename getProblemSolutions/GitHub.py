from git import Repo


def git_push(path_of_git_repo, file_name, commit_massage):
    print ('trying to push ' + str(file_name) + ' commit massage : ' + commit_massage)
    try:
        repo = Repo(path_of_git_repo)
        repo.index.add(file_name)
        repo.index.commit(commit_massage)
        origin = repo.remote(name='origin')
        origin.push()
        print ('pushed OK')
    except Exception as e:
        print ('there is an error in push')
        print (e)
