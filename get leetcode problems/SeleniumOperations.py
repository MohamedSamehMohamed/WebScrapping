from webdriver_manager.chrome import ChromeDriverManager
from selenium import webdriver
import time


def openUrl(driver, url):
  for i in range(5):
      try:
          if driver.current_url == url:
              break
          driver.get(url)
          # wait page for loading 
          time.sleep(3)
      except:
          time.sleep(1)
  # if we can't open the url 
  if driver.current_url != url:
      raise Exception('cant open the url')
    
def createDriver():
  chrome_options = webdriver.ChromeOptions()
  chrome_options.add_argument("start-maximized")
  chrome_options.add_argument("--disable-extensions")
  prefs = {"profile.default_content_setting_values.notifications" : 2}
  chrome_options.add_experimental_option("prefs",prefs)
  driver = webdriver.Chrome(ChromeDriverManager().install(), chrome_options=chrome_options)
  return driver
