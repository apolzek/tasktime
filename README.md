# tasktime
Run commands and scripts at scheduled intervals

## Install and Use

```
wget https://github.com/apolzek/tasktime/archive/tasktime-v2020-10.tar.gz 
tar -xf tasktime-v2020-10.tar.gz
cd tasktime-tasktime-v2020-10/
chmod +x tasktime && sudo mv tasktime /usr/local/bin/
tasktime
```

## Purpose

This project aims to make life easier for Linux administrators. You can automate a task simply and quickly.

*tested*: **Ubuntu 20.04 LTS** <br />
*gcc:* **9.3.0**<br />
*GNU Make* **GNU Make 4.2.1**


![](https://img.icons8.com/clouds/2x/linux-client.png)

1) Run: ```$make``` to compile and generate the executable

2) See the examples and start using:

### Some usage examples

action: Get the last lines of the log file every 1 minute
```
tasktime -M -t 1 -S "tail -n10 /var/log/auth.log"
```

action: Check if folder /var/log is empty every 4 seconds
```
tasktime -s -t 4 -S '[ "$(ls -A /var/log)" ] && echo "Not empty" || echo "Empty"'
```

action: Checks the HTTP return code for a URL every 1 hour
```
tasktime -H -t 1 -S "curl -I --silent http://ifconfig.me | grep HTTP"
```
