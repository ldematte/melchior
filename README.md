Melchior
========

Melchior - showcase if patterns for networked and concurrent systems.

I wrote this code during the Networking course at the University of Trento. The main purpose was to explore different ways and [patterns to build networked software](http://www.cs.wustl.edu/~schmidt/POSA/POSA2/); for example, it uses [Reactor](Reactor.h), [Scheduler](Scheduler.h), [Asynchronous Completion Token](ClassLib/IOCP.h) (borrowed and adapted from the great IOCP code written by Jeffrey Richter), [Scoped Locking](ThreadMutexGuard.h). 

To test it, I build a small application that acted as a very basic "sniffer", which sends ICMP messages pooling for devices, and then intercepting answers and packets on the local LAN (using the low-level winsock2 API), dispatching and parsing them.

It uses code and helpers provided by Jeffrey Richter and John Robbins in their books [Programming server-side applications for Microsoft Windows 2000](http://books.google.it/books/about/Programming_server_side_applications_for.html?id=eb5QAAAAMAAJ&redir_esc=y) and [Debugging Applications](http://www.amazon.com/Debugging-Applications-DV-MPS-Programming-Robbins/dp/0735608865)

The code is released under the 2-clause BSD license (basically, you can do whatever you like with it :))
