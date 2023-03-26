from selenium.webdriver.common.by import By


class Problem:
    def __init__(self, problem_name, submission_link, real_name, submission_lang):
        self.problem_name = problem_name
        self.submission_link = submission_link
        self.real_name = real_name
        self.submission_lang = submission_lang

    def get_store_name(self):
        problem_name = self.problem_name.split('-')[1]
        problem_name = self.real_name + '-' + problem_name
        return problem_name


def get_submissions(rows):
    problems = []
    for row in rows:
        columns = row.find_elements(By.TAG_NAME, 'td')
        problem_name = columns[3].text
        problem_link = columns[3].find_element(By.TAG_NAME, 'a').get_attribute('href')
        lang = columns[4].text

        # Check if the code can be seen
        # if there is element with class name 'hiddenSource'
        # so it is a code that can't be seen
        can_see_code = False
        try:
            columns[0].find_element(By.CLASS_NAME, 'hiddenSource')
        except:
            can_see_code = True
        if not can_see_code:
            continue

        if columns[5].text == 'Accepted':
            submission_id = columns[0].text
            contest_id = get_contest_id(problem_link)
            submission_link = 'https://codeforces.com/{}/submission/{}'.format(contest_id, submission_id)

            real_name = get_problem_name(problem_link)
            problems.append(Problem(problem_name, submission_link, real_name, lang))

    return problems


def get_problem_name(problem_link):
    try:
        link_parts = problem_link.split('/')
        contest_id = ''
        problem_order = ''
        for i, part in enumerate(link_parts):
            if part in ('gym', 'contest'):
                contest_id = link_parts[i + 1]
                problem_order = link_parts[i + 3]
                break
        if not contest_id or not problem_order:
            return -1
        return '{}{}'.format(contest_id, problem_order)
    except Exception as e:
        print(e)
        return 'problem-with-out-a-name'


def get_problem_data(problem_name, dic_problem_data):
    problem_meta = dic_problem_data.get(problem_name, -1)
    tags = ''
    rating = ''
    if 'tags' in problem_meta:
        tags = 'Problem Tags: ' + str(problem_meta['tags'])
    if 'rating' in problem_meta:
        rating = ' Problem Rate: ' + str(problem_meta['rating'])
    problem_meta = tags + rating
    return problem_meta

def get_last_page_number(driver, username):
    try:
        current_url = 'https://codeforces.com/submissions/{}/page/1'.format(username)
        driver.openUrl(current_url)
        pagination = driver.find_elements(By.CLASS_NAME, 'page-index')[-1].text
        return int(pagination)
    except Exception as e:
        print('Error getting last submission page number:', e)
        print ('assume it will be 10 pages')
        return 10

def get_submissions_row(driver):
    class_name = 'status-frame-datatable'
    table = driver.find_element(By.CLASS_NAME, class_name)
    rows = table.find_elements(By.TAG_NAME, 'tr')[1:]
    return rows

def get_contest_id(problem_link):
    link_parts = problem_link.split('/')
    for i in range(len(link_parts)):
        if link_parts[i] in ('gym', 'contest'):
            return link_parts[i] + '/' + link_parts[i+1]
    return ''