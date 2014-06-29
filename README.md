* Light work.
This repository is a collection small collection of work. Its mainly an area where I will be exploring techniques and technologies. [[file:dedication.org][Dedicated to...]]

Current projects:
#+begin_src sh :results raw
for i in `ls -D`
do
  if [ -d $i ]
  then
    echo "|" `ls -D $i | sed "s/src//" | wc -w` projects in the [[file:$i][${i}]] directory "|"
  fi
done
#+end_src

#+RESULTS:
1 projects in the [[file:c++][c++]] directory
0 projects in the [[file:emacs][emacs]] directory
1 projects in the [[file:lisp][lisp]] directory
1 projects in the [[file:lisp+c++][lisp+c++]] directory
1 projects in the [[file:networking][networking]] directory
1 projects in the [[file:python][python]] directory
0 projects in the [[file:R][R]] directory
1 projects in the [[file:R+c++][R+c++]] directory
1 projects in the [[file:sh][sh]] directory


** Setup
I've used org-babel to merge text and code together to give extra context during relearning. Most projects are will generate src code which will be located in <project>/src.

I'd advise that you use emacs and my .emacs configuration located in the emacs project directory. There will be some packages you'll need to download.

The below script will set up the required directories so that they are ready for you to use. In emacs press C-c C-c 
#+begin_src sh :results output
for i in `ls -D`
do
  if [ -d $i ] 
  then
    mkdir $i/src
    echo "Created $i/src"
  fi
done 
echo "Done."
#+end_src

#+RESULTS:
#+begin_example
Created c++/src
Created emacs/src
Created lisp/src
Created lisp+c++/src
Created networking/src
Created python/src
Created R/src
Created R+c++/src
Created sh/src
Done.
#+end_example


