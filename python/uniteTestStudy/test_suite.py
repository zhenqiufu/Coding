#! /usr/bin/env python3
# _*_ coding:utf-8 _*_

import unittest
from test_mathfunc import TestMathFunc

if __name__ == "__main__":
    suite = unittest.TestSuite()

    # 使用addTests多个testcase一起添加
    # tests = [TestMathFunc("test_add"), TestMathFunc("test_minus"), TestMathFunc("test_divide")]
    # suite.addTests(tests)

    # # 直接用addTest方法添加单个testcase
    # suite.addTest(TestMathFunc("test_multi"))

    # # aadTest + TestLoader 方式
    # # loadTestFromName(),传入模块名.TestCase名
    # suite.addTests(unittest.TestLoader().loadTestsFromName('test_mathfunc.TestMathFunc'))
    # suite.addTests(unittest.TestLoader().loadTestsFromNames(['test_mathfunc.TestMathFunc'])) # 传入列表

    # loadTestsFromTestCase() 传入TestCase
    suite.addTests(unittest.TestLoader().loadTestsFromTestCase(TestMathFunc))

    # 输出文件
    # with open('UnitetestTextReport.txt','a') as f :
    #     runner = unittest.TextTestRunner(stream=f,verbosity=2)
    #     runner.run(suite)


    # 直接运行
    runner = unittest.TextTestRunner(verbosity=2)
    runner.run(suite)