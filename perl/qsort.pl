use strict;
use warnings;

main();

sub main {
    my $arr = [-10, -10,30,321,-10,994,3,-1000,213,54];
    print "Before sort: " . join(',', @$arr);
    my $sorted_arr = quick_sort($arr);
    print "\n";
    print "After sort: " . join(',', @$sorted_arr);
    print "\n";
}

sub quick_sort {
    my ($arr) = @_;
    return $arr if (scalar(@$arr) == 0);

    my ($left, $right, $pivot_arr) = partition($arr);
    $left = quick_sort($left);
    $right = quick_sort($right);
    my @sorted_arr;
    push @sorted_arr, @$left;
    push @sorted_arr, @$pivot_arr;
    push @sorted_arr, @$right;
    return \@sorted_arr;
}

sub partition {
    my ($arr) = @_;

    my $pivot = $arr->[0];
    my ($left, $right, $pivot_arr) = _part_partition($arr, $pivot);
    return ($left, $right, $pivot_arr);
}

sub _part_partition {
    my ($arr, $pivot) = @_;
    my @left;
    my @right;
    my @pivot;

    foreach my $elem (@$arr) {
        if ($elem < $pivot) {
            push @left, $elem;
        } elsif ($elem > $pivot) {
            push @right, $elem;
        } else {
            push @pivot, $pivot;
        }
    }
    return (\@left, \@right, \@pivot);
}
