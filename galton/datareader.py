import urllib2
import numpy as np

class BrokenData(Exception):
    pass

def read_board_data():
    url = 'http://10.10.10.10/galton_counts.txt'

    try:
        conn = urllib2.urlopen(url, timeout=2)
        counts = conn.readline()
        conn.close()
    except:
        return np.random.random_integers(0,40,13) # [0]*13

    counts = counts.rstrip().split(',')
    if counts[0] != 'a' or counts[-1] != 'z':
        raise BrokenData()
    counts = counts[1:-1]

    try:
        counts = map(int,counts)
    except ValueError:
        raise BrokenData()

    return counts

if __name__ == '__main__':
    data = read_board_data()
    print data
