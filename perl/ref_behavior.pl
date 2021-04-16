#!/usr/bin/env perl
#
# Words in this code:
#     pointer: a value of an address of data in RAM.
#     value:   a value of data in RAM.

use strict;
use warnings;

main();

sub main {
    my $str = 'first';
    my $strRef = \$str;

    &ref_routine($strRef);
    print "$$strRef\n";

    # output : firstsecond

    my $retVal = &val_routine($strRef);
    print "$retVal\n";
    # output : firstsecondthird

    print "$$strRef\n";
    # output : firstsecond

    &another_ref($strRef);
    print "$$strRef}\n";
    # output : firstsecond
}

sub ref_routine {
    my ($ref) = @_;
    $$ref .= 'second'; # change a value in a pointer.
}

sub val_routine {
    my ($ref) = @_;
    my $returnValue = $$ref; # copy a value in a pointer.
    $returnValue .= 'third'; # change the copied value.
    return $returnValue;
}

sub another_ref {
    my ($ref) = @_;
    $ref = []; # change a pointer in $ref.
}
