# csse332-labs-branstlh
=======
# CSSE332 Labs

This repository contains all of the starter code for the user space lab
assignments in CSSE332: Operating Systems at Rose-Hulman.

To clone this repository and keep a __private__ copy of your lab submissions, please follow the steps below.

## 1. Create a __private__ repository

Using your Github account, create a new, empty, and __private__ repository. Do
not initialize that repository with a README file, do not create a license, and
make sure that the repository is completely empty.

The repository you created will host all of your source code for submitting
labs, so we suggest you give it a meaningful name, such as
`csse332-labs-<username>` where `<username>` is your RHIT username. For example,
I would want to create a repository called `csse332-labs-noureddi`.

In what follows, we will assume that your repository is called
`csse332-labs-user`.

### Make sure your repository is private

Please make sure your created repository is __private__. Posting your solution
to the labs on a public repository is considered a form of academic misconduct,
and will be treated as such if discovered.

## 2. Clone the repository

In your terminal window, clone the labs repository using the following command:

```shell
$ git clone git@github.com:rhit-csse332/csse332-labs-user.git`
...
warning: You appear to have cloned an empty repository.
```

Note that the line `warning: You appear to have cloned an empty repository.`
should show up when you clone this repository. If it does not show, then you
repo is not empty. Go back to github, delete it, and create a new empty
repository.

## 3. Adjust the repository's remote

We would like to set up your repository in a way that when you `pull`, you would
get updates from the class's repository. However, when you finish a lab and
commit your changes, we would like to `push` those changes to your private
repository.

To do so, first navigate to your labs repository:

```shell
$ cd csse332-labs-user/
```

Your directory should be empty (confirm that with `ls`). Next, let's set the
`pull` origin to point to the class repository. To do so, use the following:

```shell
$ git remote add upstream git@github.com:rhit-csse332/csse332-labs.git
```

Then, confirm that a new remote shows up in your repository, as follows:

```shell
$ git remote -v
origin  git@github.com:nouredd2/csse332-labs-user.git (fetch)
origin  git@github.com:nouredd2/csse332-labs-user.git (push)
upstream        git@github.com:rhit-csse332/csse332-labs.git (fetch)
upstream        git@github.com:rhit-csse332/csse332-labs.git (push)
```

## 4. Fetch the changes from the class repository

Now, let's obtain the class content from the class repository using:

```shell
$ git fetch upstream
remote: Enumerating objects: 4, done.
remote: Counting objects: 100% (4/4), done.
remote: Compressing objects: 100% (4/4), done.
remote: Total 4 (delta 0), reused 4 (delta 0), pack-reused 0
Unpacking objects: 100% (4/4), 2.51 KiB | 366.00 KiB/s, done.
From github.com:rhit-csse332/csse332-labs
 * [new branch]      main       -> upstream/main
```

Then, pull the changes:

```shell
$ git pull upstream main
From github.com:rhit-csse332/csse332-labs
 * branch            main       -> FETCH_HEAD
```

Now, if you check the content of your directory, the starter code for the labs
will show up in there.

## 5. Push initial commit to your private repository

Now, we need to sync things up to your private repository, to do so, you should
user:

```shell
$ git push origin main
Enumerating objects: 4, done.
Counting objects: 100% (4/4), done.
Delta compression using up to 8 threads
Compressing objects: 100% (4/4), done.
Writing objects: 100% (4/4), 2.53 KiB | 2.53 MiB/s, done.
Total 4 (delta 0), reused 0 (delta 0), pack-reused 0
To github.com:nouredd2/csse332-labs-user.git
 * [new branch]      main -> main
```

Using your browser, verify that everything now shows up on your
`csse332-labs-user` private repository.

---

Last edited on Wed 22 Nov 2023 by Mohammad Noureddine. If you find typos or
errors, please open an issue on Github.
