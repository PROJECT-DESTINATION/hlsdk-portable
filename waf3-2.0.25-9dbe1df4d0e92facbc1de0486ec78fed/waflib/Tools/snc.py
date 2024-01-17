#! /usr/bin/env python
# encoding: utf-8
# WARNING! Do not edit! https://waf.io/book/index.html#_obtaining_the_waf_file

#!/usr/bin/env python
# encoding: utf-8
# Krzysztof Kosiński 2014

"""
Detect the Clang C compiler
"""

from waflib.Tools import ccroot, ar, gcc
from waflib.Configure import conf

@conf
def find_snc(conf):
	"""
	Finds the program clang and executes it to ensure it really is clang
	"""
	cc = conf.find_program('ps3ppusnc', var='CC')
	conf.get_cc_version(cc)
	conf.env.CC_NAME = 'ps3ppusnc'
	cxx = conf.find_program('ps3ppusnc', var='CXX')
	#conf.get_cxx_version(cxx)
	conf.env.cxxshlib_PATTERN = "lib%s.sprx"
	conf.env.CXX_NAME = 'ps3ppusnc'
	print(conf.find_program('ps3ppuld64', var='LINK_CXX'))

def configure(conf):
	conf.find_snc()
	conf.gcc_common_flags()
	conf.gcc_modifier_platform()
	conf.cc_load_tools()
	conf.cxx_load_tools()
	conf.cc_add_flags()
	conf.cxx_add_flags()
	conf.link_add_flags()
