import time


def print_hello():
    print("Hello")


if __name__=="__main__":
    start_time = time.time()
    interval = 1
    i = 1
    while True:
        time.sleep(start_time + i*interval - time.time())
        i+= 1
        print_hello()