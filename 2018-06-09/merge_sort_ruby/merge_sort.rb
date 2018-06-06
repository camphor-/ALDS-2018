$merge_count = 0

def merge(series, left, mid, right)
  ls = series[left...mid] + [Float::INFINITY]
  rs = series[mid...right] + [Float::INFINITY]

  li = 0
  ri = 0
  (left...right).each do |i|
    $merge_count += 1
    if ls[li] >= rs[ri]
      series[i] = rs[ri]
      ri += 1
    else
      series[i] = ls[li]
      li += 1
    end
  end
end

def merge_sort(series, left, right)
  if left + 1 < right
    mid = (left + right) / 2
    merge_sort(series, left, mid)
    merge_sort(series, mid, right)
    merge(series, left, mid, right)
  end
end

if __FILE__ == $0
  n = $stdin.gets.to_i
  series = $stdin.gets.strip.split(' ').map(&:to_i)
  merge_sort(series, 0, n)
  puts series.join(' ')
  puts $merge_count
end