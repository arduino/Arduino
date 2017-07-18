#!/usr/bin/env python2
#vim:set fileencoding=utf-8 sw=2 expandtab

from transifex import Transifex
import requests
import getpass
import sys
import time

def main():
  print 'Use your account to talk with Transifex.'
  user = raw_input('Username: ')
  passwd = getpass.getpass('Password: ')
  trans = Transifex(user, passwd)

  for lang in sys.argv[1:]:
    fname = 'Resources_%s.po' % lang
    sys.stdout.flush()
    try:
      lang = trans.canonical_lang(lang)
      pull(trans, lang, fname)
    except RuntimeError, e:
      print e.message
      continue
    except IOError, e:
      print e.strerror
      continue

def pull(trans, lang, fname):
  count = 0
  print "Updating %s from Transifex...\n" % fname,
  sys.stdout.flush()
  while count < 5:
    count += 1
    try:
      trans.pull(lang, fname)
      return
    except requests.exceptions.HTTPError, e:
      print " *** Retrying %s from Transifex...\n" % fname,
      time.sleep(3)
      sys.stdout.flush()

  if count >= 5:
    raise Exception("Too many retries")

if __name__ == '__main__':
  main()
