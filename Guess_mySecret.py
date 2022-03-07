import random,os,time

global times      #声明全局变量
times = 0         #初始化连续游戏次数

def main():                         #定义猜数主函数
    secret = random.randint(1,99)   #定义猜数范围
    guess = 0                       #初始化用户输入
    tries = 0                       #初始化尝试次数

    global times  #使用全局变量
    times += 1    #连续游戏次数+1
    print (  time.strftime('%Y-%m-%d %H:%M:%S',time.localtime(time.time())),"\n---------------YOU HAVE RUN THE PROGRAM CONTINUOUSLY ",times,"---------------" )
    
    print ("AHOY I'm the Dread Pirate Roberts, and I have a secret!")
    print ("It is a number from 1 to 99. I will give you 6 tries.\n")
    while guess != secret and tries < 6:   #如果没猜中且还有机会，则：
        try:
            guess = int(input("What is your guess? "))
            if guess < secret:
                print ("Too low, ye scurvy dog!")
            elif guess > secret:
                print ("Too high, landlubber!")

            tries += 1                         #尝试次数+1
        except:
            print("\n\n\n !!!error!!!\n")
            main()

    print("\n")#以下为判断语句：
    if tries == 1 and guess == secret:     #一猜即中，则：
        print("How lucky! You guessed it once!")
    elif guess == secret:                  #尝试多次猜中，则：
        print ("Avast! Ye got it by",tries,"tries! Found my secret,ye did!")
    else:                                  #机会用尽，则：
        print ("!!No more guesses! Better luck next time, matey!")
        print ("The secret number was [",secret,"]")

    os.system("pause")
    play_again()                    #运行函数：判断是否重新开始

def play_again():                   #play_again函数：是否重新开始(y/n)
    while True:
        print("\n")
        retry = input("Would you like to play again?(yes or no) : ")
        if retry == "yes" or retry == "y" or retry == "":
            print ("\n")
            main()
        if retry == "no" or retry == "n":
            print("Bye!")
            exit()
        else:
            print("I'm sorry I could not recognize what you entered\nPlease enter again...\n")
            play_again()

main()                      #从main函数开始运行
