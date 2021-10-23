import urllib.request
import urllib.parse
import json
import requests
from sqlitedict import SqliteDict
import util
import os

db_path = 'luogu.db'
user_agent = r'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/44.0.2403.157 Safari/537.36'

def withUrl(u):
    return "https://www.luogu.com.cn/"+u

def luogu_key(id):
    return "P"+str(id)

def is_int(s):
    try: 
        int(s)
        return True
    except ValueError:
        return False

class Luogu:
    def __init__(self):
        self.dict = self.init_db()
        self.finished = []
        self.flasks = []
        # read user
        p = util.get_root("oj", "luogu")
        entries = os.listdir(p)
        for k in entries:
            if k.endswith(".cpp"):
                self.finished.append(k)
            elif k.endswith(".md"):
                self.flasks.append(k)

    def init_db(self):
        d = SqliteDict(util.get_db('luogu.sqlite'), autocommit=True)
        return d

    def close_db(self):
        self.dict.close()

    def get_tag_problems(self, tag):
        problems = self.get_all_problems()
        datas = [] 
        for k in problems:
            try:
                j = json.loads(problems[k])
                tags = j['tags']
                if len(tags) > 0 and t in tag:
                    datas.append(j)
            except Exception as e:
                print("unknow key:", k, e)
                pass
        return datas

    def get_all_problems(self):
        d = {}
        for k, v in self.dict.iteritems():
            if k.startswith("P"):
                d[k] = v
        return d

    def save_problem(self, id, content):
        self.dict[id] = content
        self.dict.commit()

    def get_problem_content(self, id):
        v = self.dict.get(id)
        return v

    def get_level(self, id):
        content = self.get_problem_content(id)
        if content == None:
            print("title not exist:", id)
            return str(id)
        j = json.loads(content)
        return j['difficulty']

    def check_finish(self, id):
        for k in self.finished:
            if k.startswith(id):
                return True
        return False

    def check_flask(self, id):
        for k in self.flasks:
            if k.startswith(id):
                return k
        return ""

    def get_problem(self, id):
        content = self.get_problem_content(id)
        if content == None:
            print("title not exist:", id)
            return str(id)
        j = json.loads(content)
        return j

    def get_title(self, id):
        content = self.get_problem_content(id)
        if content == None:
            print("title not exist:", id)
            return str(id)
        j = json.loads(content)
        return j['title']

    def get_update_db_time(self):
        t = self.dict.get("luogu_update_db_time")
        if t == None:
            return 0
        return t

    def save_update_db_time(self):
        self.dict["luogu_update_db_time"] = util.now()

    def update_db(self):
        t = self.get_update_db_time()
        if util.now()-t < 30*24*3600*1000: # 30 天更新一次
            return

        for page in range(1,137):
            url = withUrl(f"problem/list?page={page}&_contentOnly=1")
            f = urllib.request.urlopen(url)
            content = f.read().decode('utf-8')
            qlist = json.loads(content)

            try:
                # for q in qlist['stat_status_pairs']:
                for q in qlist["currentData"]["problems"]["result"]:
                    id = q['pid']
                    level = q['difficulty']
                    title = q['title']
                    print("id:", id, level, title)
                    value = json.dumps(q)
                    self.save_problem(id, value)
                self.save_update_db_time()
            except Exception as e:
                print("luogu update db error:", e)
                pass


if __name__ == '__main__':
    luogu = Luogu()
    luogu.update_db()