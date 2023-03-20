from webdriver_manager.chrome import ChromeDriverManager
from selenium.webdriver.common.action_chains import ActionChains
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.keys import Keys
from selenium import webdriver
from bs4 import BeautifulSoup
import time


class WebDriver:
    def __init__(self):
        chrome_options = webdriver.ChromeOptions()
        chrome_options.add_argument("start-maximized")
        chrome_options.add_argument("--disable-extensions")
        prefs = {"profile.default_content_setting_values.notifications": 2}
        chrome_options.add_experimental_option("prefs", prefs)
        self.driver = webdriver.Chrome(ChromeDriverManager().install(), options=chrome_options)

    def clickEsc(self):
        ActionChains(self.driver).send_keys(Keys.ESCAPE).perform()

    def click(self, xpath):
        button = self.driver.find_element(By.XPATH, xpath)
        self.driver.execute_script("arguments[0].click();", button)

    def send_keys(self, xpath, key):
        WebDriverWait(self.driver, 20).until(EC.element_to_be_clickable((By.XPATH, xpath))).send_keys(key)

    def openUrl(self, url):
        for i in range(5):
            try:
                if self.driver.current_url == url:
                    break
                self.driver.get(url)
                time.sleep(3)
            except:
                time.sleep(1)
        if self.driver.current_url != url:
            raise Exception('cant open the url')

    def readSourceLines(self):
        codeTable = self.driver.find_element(By.XPATH, '//*[@id="program-source-text"]')
        codeLines = codeTable.find_elements(By.TAG_NAME, 'li')
        lines = ''
        for i in codeLines:
            lines += i.text + '\n'
        return lines

    def getTableTR(self, className):
        table = self.driver.find_element(By.CLASS_NAME, className)
        rows = table.find_elements(By.TAG_NAME, 'tr')[1:]
        return rows
    def find_element(self, method, name):
        return self.driver.find_element(method, name)
    def find_elements(self, method, name):
        return self.driver.find_elements(method, name)