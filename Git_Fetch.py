import os

# GIT_BRANCH = "git checkout feature/gwm_v3.5_p03_es16_dev_autoshow"
# GIT_BRANCH = "git checkout feature/gwm_v.3.5_dbc_v4.2.1"
# GIT_BRANCH = "git checkout feature/gwm_v.3.5_b02_dbc_v1.1"
# GIT_BRANCH = "git checkout feature/gwm_v3.5_p03_dbc_v2.0"
#GIT_BRANCH = "git checkout feature/p02chn_dbc_v1.0"
#GIT_BRANCH = "git checkout gwm_v3.5_dev"
#GIT_BRANCH = "git checkout feature/p02_com_test_v4.0"


GIT_BRANCH = "git fetch "

os.chdir('./Build')
print(os.popen(GIT_BRANCH).read(),end='')
print("Build Update Finished\n")
os.chdir('../')

os.chdir('./Davinci')
print(os.popen(GIT_BRANCH).read(),end='')
print("Davinci Update Finished\n")
os.chdir('../')

os.chdir('./Driver')
print(os.popen(GIT_BRANCH).read(),end='')
print("Driver Update Finished\n")
os.chdir('../')

os.chdir('./IPC_Common')
print(os.popen(GIT_BRANCH).read(),end='')
print("IPC_Common Update Finished\n")
os.chdir('../')

os.chdir('./SWC')
print(os.popen(GIT_BRANCH).read(),end='')
print("SWC Update Finished\n")
os.chdir('../')

os.chdir('./SWC_CLUSTER')
print(os.popen(GIT_BRANCH).read(),end='')
print("SWC_CLUSTER Update Finished\n")
os.chdir('../')

SUCCESS = \
'''\n    ____ _  _ ____ ____ ____ ____ ____\n \
   [__  |  | |    |    |___ [__  [__ \n \
   ___] |__| |___ |___ |___ ___] ___] \n\n'''

print(SUCCESS)

os.system('pause')