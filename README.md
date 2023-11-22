# CSSE332 Labs

This repository contains all of the starter code for the user space lab
assignments in CSSE332: Operating Systems at Rose-Hulman.

To clone this repository and keep a __private__ copy of your lab submissions,
please follow the steps below.

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

## Adjust the repository's remote

We would like to set up your repository in a way that when you `pull`, you would
get updates from the class's repository. However, when you finish a lab and
commit your changes, we would like to `push` those changes to your private
repository.

To do so, first navigate to your labs repository:

```shell
$ cd csse332-labs-user/
```

