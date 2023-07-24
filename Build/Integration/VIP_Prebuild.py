# -*- coding: utf-8 -*-

import os
import sys
import argparse
import argparse

global BUILD_COUNT
BUILD_COUNT = 0

parser = argparse.ArgumentParser(description='verify build')
parser.add_argument('--GERRIT_EVENT_TYPE',type=str,default=None)
parser.add_argument('--GERRIT_PROJECT',type=str,default=None)
parser.add_argument('--GERRIT_REFSPEC',type=str,default=None)
parser.add_argument('--WORKSPACE',type=str,default=None)
args=parser.parse_args()


def gerrit_pull():
    print("GERRIT_EVENT_TYPE:" + args.GERRIT_EVENT_TYPE)
    print("GERRIT_PROJECT:" + args.GERRIT_PROJECT)
    
    if args.GERRIT_EVENT_TYPE ==  "patchset-created":
        print("cherry-pick build")
        if "v3.5/ipc_common_gateway" == args.GERRIT_PROJECT:
            cmd = "cd " + args.WORKSPACE + "\work\SWC\IPC_Common & git fetch ssh://gerrit.sh.noboauto.com:29418/" + args.GERRIT_PROJECT + " " + args.GERRIT_REFSPEC + " && git cherry-pick FETCH_HEAD"
        elif "V3.5/VIP/HSM" == args.GERRIT_PROJECT:
            cmd = "cd " + args.WORKSPACE + "\work\HSM & git fetch ssh://gerrit.sh.noboauto.com:29418/" + args.GERRIT_PROJECT + " " + args.GERRIT_REFSPEC + " && git cherry-pick FETCH_HEAD"
        elif "V3.5/VIP/BootManage" == args.GERRIT_PROJECT:
            cmd = "cd " + args.WORKSPACE + "\work\BootManage & git fetch ssh://gerrit.sh.noboauto.com:29418/" + args.GERRIT_PROJECT + " " + args.GERRIT_REFSPEC + " && git cherry-pick FETCH_HEAD"
        else:
            cmd = "cd " + args.WORKSPACE + "\work & git fetch ssh://gerrit.sh.noboauto.com:29418/" + args.GERRIT_PROJECT + " " + args.GERRIT_REFSPEC + " && git cherry-pick FETCH_HEAD"
        print(cmd)
        os.system(cmd)
    else:
        print("merge build") 
        
        
def build_verify():
    global BUILD_COUNT
    cmd = "cd Release && call Release.bat > " + args.WORKSPACE + "\work\Build\Integration\\build.log 2>&1"
    print(cmd)
    if os.system(cmd):
        print("Build ERROR!!!")
    else:
        print("Build Successfully!!!")
    BUILD_COUNT = BUILD_COUNT + 1
    print("build the " + str(BUILD_COUNT) + " times")
    check_buildlog()
    
def check_buildlog():
    BUILDERROR = ""
    LICENSEERROR = ""
    for line in open("build.log"):
        if "Error: build failed" in str(line):
            print("find build error:" + str(line))
            BUILDERROR = "ERROR"
            
    for line in open("build.log"):         
        if "No licenses available" in str(line):
            print("can not obtain ghs license:" + str(line))
            LICENSEERROR = "ERROR"

    if BUILDERROR == "":
        print("build success")
        os.system("type build.log")
        exit(0)
    elif BUILDERROR == "ERROR" and  LICENSEERROR == "":
        print("build failed becuase of code error")
        os.system("type build.log")
        exit(1)
    elif BUILDERROR == "ERROR" and  LICENSEERROR == "ERROR":
        global BUILD_COUNT
        if BUILD_COUNT < 3:
            print("find build error and licnese error , need rebuild again")
            build_verify()
        else:
            print("rebuild error 3 times, exit with error")
            exit(1)
            
if __name__ == '__main__':
    gerrit_pull()
    build_verify()
