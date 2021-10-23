from graphviz import Digraph
import theme
import util
import os
from pathlib import Path
import datamap
import luogu as lg
from svgpathtools import svg2paths
from bs4 import BeautifulSoup
import platform_view

class LuoguView(platform_view.PlatformView):
    def __init__(self, luogu):
        self.luogu = luogu
        self.m = None
        self.slug = "luogu"

    def check_finish(self, title):
        return self.luogu.check_finish(title)

    def get_problem(self, title):
        return self.m.problem_map[title]

    def check_flask(self, title):
        return self.luogu.check_flask(title)

    def is_valid_title(self, title):
        return title.isdigit() or (title[0] == 'P' and title[1:].isdigit())

    def post_process(self, path):
        self.add_finish_icon(path)

    def generate_luogu(self, luogu, file, slug, out_name):
        c = util.get_file_content(util.get_map(file))
        m = datamap.DataMap(c)
        self.m = m
        g = Digraph('scallions', encoding='utf-8')

        for n in m.nodes:
            if n.is_root:
                count = self.get_module_problem_count(m)
                label = "%s(%s)" % (n.name, str(count))
                # 根节点
                g.node(name=n.name, label=label, style='filled', target="_parent", href=f"https://www.luogu.com.cn/problem/list?page=1&orderBy=difficulty&order=asc&keyword={slug}", 
                    fontsize='14',
                    fillcolor="orangered", color='lightgrey', fontcolor="white", fontname="Microsoft YaHei", shape='box')
            else:
                # 普通模块节点
                label = "%s(%s)" % (n.name, str(len(n.problems)))
                g.node(name=n.name, label=label, style='filled', fillcolor="lightslategray", color='lightgrey', 
                    fontsize='12',
                    fontcolor="white", fontname="Microsoft YaHei", shape='box')
                g.edge(n.parent, n.name, color=theme.color_arrow)

            # add problem
            last = ""
            for p in n.problems:
                title = luogu.get_title(p.id)
                level = luogu.get_level(p.id)
                problem = luogu.get_problem(p.id)
                idstr = str(p.id)
                if title == None:
                    continue 
                title = idstr+". "+title
                color = "lightgrey"

                if level <= 2:
                    color = "greenyellow"
                elif level <= 5:
                    color = "orange"
                elif level <= 7:
                    color = "red"
                else:
                    print("unknown level:", level)
                    continue

                # 题目节点
                g.node(name=idstr, label=title, target="_parent", href="https://www.luogu.com.cn/problem/"+p.id, 
                        color=color, fontname="Microsoft YaHei", fontsize='12', shape='box')

                if len(last) > 0:
                    g.edge(last, idstr, color=theme.color_arrow)
                else:
                    g.edge(n.name, idstr, color=theme.color_arrow)
                last = idstr

        g.format = 'svg'
        g.render(filename=util.get_images(out_name))
        os.remove(util.get_images(out_name))
        self.post_process(util.get_images(out_name)+".svg")

def process():
    luogu = lg.Luogu()
    view = LuoguView(luogu)
    luogu.update_db()
    view.generate_luogu(luogu, "luogu/luogu.txt", "luogu_test", "luogu_test")
    luogu.close_db()
