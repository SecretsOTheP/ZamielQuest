#!/usr/bin/perl -w

use strict;
use IO::Socket::INET;

# Force a flush after every write
$| = 1;

if ($#ARGV < 1) {
	print "usage: corpseDrag.pl <pid> <CorpseName>\n";
	exit(1);
}

my $PID = $ARGV[0];
my @CorpseList = ();

for (my $i = 1; $i < $#ARGV + 1; $i++) {
	push @CorpseList, $ARGV[$i];
}

# Subroutines
sub sendCommand {
	my ($socket, $client_socket);
	my $data = shift;
	$data = "$PID " . $data;

	$socket = new IO::Socket::INET (
		PeerHost => '127.0.0.1',
		PeerPort => '10000',
		Proto => 'tcp',
	) or die "Error in socket creation: $!\n";

	print $socket "$data\n";
	$socket->close();
	select(undef, undef, undef, .1); # To fix multiple sends
}

while () {
	foreach (@CorpseList) {
		sendCommand("/corpsedrag $_");
		select(undef, undef, undef, .1); # To reduce the chance that the race condition happens =(
	}

}