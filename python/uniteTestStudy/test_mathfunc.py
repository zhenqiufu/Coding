#! /usr/bin/env python3
# _*_ coding:utf-8 _*_

import unittest
from mathfunc import *

class TestMathFunc(unittest.TestCase):
    def setUp(self):
        print("doing sth before test")

    def tearDown(self):
        print("doing sth after test")

    def test_add(self):
        self.assertEqual(3,add(1,2))
        self.assertNotEqual(3,add(1,1))
    
    def test_minus(self):
        self.assertEqual(1,minus(3,2))

    def test_multi(self):
        self.assertEqual(6,multi(2,3))

    def test_divide(self):
        self.assertEqual(2,divide(6,3))
        self.assertEqual(2,divide(5,2))


if __name__ == "__main__":
    unittest.main()