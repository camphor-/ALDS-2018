require 'test/unit'
require_relative './merge_sort'

class TestSample < Test::Unit::TestCase
  def test_merge
    left_sorted = (1..100).to_a.sample(10).sort
    right_sorted = (1..100).to_a.sample(20).sort
    test_series = left_sorted + right_sorted
    expected_series = test_series.sort

    merge(test_series, 0, 10, 30)
    assert_equal test_series, expected_series
  end

  def test_merge_sort
    test_series = (1..100).to_a.sample(30)
    expected_series = test_series.sort

    merge_sort(test_series, 0, 30)
    assert_equal test_series, expected_series
  end
end
