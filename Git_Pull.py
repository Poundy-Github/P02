import os

GIT_PULL = "git pull --rebase"

os.chdir('./Build')
print(os.popen(GIT_PULL).read(),end='')
print("Build Update Finished\n")
os.chdir('../')

os.chdir('./Davinci')
print(os.popen(GIT_PULL).read(),end='')
print("Davinci Update Finished\n")
os.chdir('../')

os.chdir('./Driver')
print(os.popen(GIT_PULL).read(),end='')
print("Driver Update Finished\n")
os.chdir('../')

os.chdir('./IPC_Common')
print(os.popen(GIT_PULL).read(),end='')
print("IPC_Common Update Finished\n")
os.chdir('../')

os.chdir('./SWC')
print(os.popen(GIT_PULL).read(),end='')
print("SWC Update Finished\n")
os.chdir('../')

os.chdir('./SWC_CLUSTER')
print(os.popen(GIT_PULL).read(),end='')
print("SWC_CLUSTER Update Finished\n")
os.chdir('../')

SUCCESS = \
'''\n    ____ _  _ ____ ____ ____ ____ ____\n \
   [__  |  | |    |    |___ [__  [__ \n \
   ___] |__| |___ |___ |___ ___] ___] \n\n'''

print(SUCCESS)

os.system('pause')