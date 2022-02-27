import sys



# 因为8位，只需要判断年即可

def leap_year(year):
    """检查是否闰年

    Args:
        year (int): 年份

    Returns:
        bool: 是否闰年

    >>> leap_year(2000)
    True
    >>> leap_year(2001)
    False
    >>> leap_year(2004)
    True
    >>> leap_year(2100)
    False
    """
    if (year % 4 == 0 and year%100 != 0) or year %400 == 0:
        return True
    return False

def check(date):
    """检查日期是否合法

    Args:
        date (str): 8位数日期，不一定合法有效

    Returns:
        bool: 是否为合法日期

    >>> check("20111303")
    False
    >>> check("20040229")
    True
    >>> check("20040230")
    False
    >>> check("20050132")
    False
    """
    year = int(date[:4])
    mons = [31,28,31,30,31,30,31,31,30,31,30,31]
    mon = int(date[4:6])
    day = int(date[-2:])
    if day < 1 or day > 31 or mon < 1 or mon > 12:
        return False
    if mon == 2:
        if leap_year(year):
            if day > 28+1:
                return False
        else:
            if day > 28:
                return False
    elif day > mons[mon-1]:
        return False
    return True

def main():
    start = sys.stdin.readline().strip()
    end = sys.stdin.readline().strip()


    syear = int(start[:4])
    smon = int(start[4:6])
    sday = int(start[-2:])

    eyear = int(end[:4])
    emon = int(end[4:6])
    eday = int(end[-2:])
    cnt = 0
    for year in range(syear, eyear+1):
        ss = str(year) + str(year)[::-1]
        if ss >= start and ss <= end and check(ss):
            # print(ss)
            cnt += 1

    print(cnt)



if __name__ == '__main__':
    main()