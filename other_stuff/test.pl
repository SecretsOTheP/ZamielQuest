#!/usr/bin/perl -w

use strict;
use IPC::Open2;

my $PID = open2(undef, undef, 'ps auwx');
print "lol pid is $PID\n";