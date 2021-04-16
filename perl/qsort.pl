use strict;
use warnings;
use Data::Dumper;

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
    return $arr if (scalar(@$arr) == 1);

    my ($left, $right) = partition($arr);
    $left = quick_sort($left);
    $right = quick_sort($right);
    my @sorted_arr;
    push @sorted_arr, @$left;
    push @sorted_arr, @$right;
    return \@sorted_arr;
}

sub partition {
    my ($arr) = @_;

    my $pivot = $arr->[0];
    my ($left, $right) = _part_partition($arr, $pivot);
    if (scalar(@$right) == 0) {
        # @$rightに何も入らないケースに対応
        # leftには必ずなにか入る
        $left = [];
        $pivot = $arr->[1];
        ($left, $right) = _part_partition($arr, $pivot);
    }
    return ($left, $right);
}

sub _part_partition {
    my ($arr, $pivot) = @_;
    my @left;
    my @right;

    my $counter = 0;
    foreach my $elem (@$arr) {
        if ($elem < $pivot) {
            push @left, $elem;
        } elsif ($elem > $pivot) {
            push @right, $elem;
        } else {
            # 1回目はleft, 2回目以降はrightに入れる
            # 2回目というのは、同じ数字が複数回出たとき用の対応
            $counter++;
            if ($counter >= 2) {
                push @right, $elem;
            } else {
                push @left, $elem;
            }
        }
    }
    return (\@left, \@right);
}
