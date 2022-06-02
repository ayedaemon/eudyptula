### Tasks for [The Eudyptula Project](http://eudyptula-challenge.org/)

---


#### Vagrantfile ???

I've used generic/centos7 vagrant image for completing all the tasks. If you don't know about Vagrant, read this -> https://opensource.com/resources/vagrant

### How to use this repo ???

0. Install vagrant and virtualbox on your system.
1. Clone this repo. And `cd eudyptula`.
2. Read tasks from their respective folders and try to solve them with the help of google and manpages. I've written a [series of blogs](https://ayedaemon.github.io/series/eudyptula/) that contains the solutions and some related knowledge to guide you through the process. 
3. To use the same environment as I have in the blogs, use provided vagrant files. Once you are in the cloned repo, type `vagrant up && vagrant ssh` from your terminal and boom, you have the shell to play around. Navigate to `/vagrant_data` dir in VM, here you can find all the current directory's data (from host machine).
