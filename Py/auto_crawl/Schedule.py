import schedule
import subprocess
import time

def job():
    print("Đang thực thi ...")
    subprocess.run(['python','Craw.py'])
    subprocess.run(['python','Craw1.py'])
    subprocess.run(['python','Craw2.py'])

schedule.every(1).hours.do(job)
num=0
while True:
    schedule.run_pending()
    time.sleep(3)#3s