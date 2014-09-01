#!/usr/bin/perl -w

use strict;

if ($#ARGV < 0) {
	printf("usage: %s <pid>\n", $0);
	exit(1);
}

my $PID = $ARGV[0];
my $Heading = 0;

while () {
	$Heading += 22.5;
	$Heading = 0 if ($Heading == 360);
	system "./face $PID $Heading";
	select(undef, undef, undef, .4);
}