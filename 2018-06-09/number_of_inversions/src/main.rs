fn read_lines() -> Vec<String> {
    use std::io::Read;

    let mut buf = String::new();
    std::io::stdin().read_to_string(&mut buf).unwrap();
    return buf.lines().map(|e| e.to_string()).collect::<Vec<_>>();
}

fn main() {
    let input = read_lines();
    let n: usize = input[0].parse().unwrap();
    let mut series = input[1].split_whitespace().map(|s| s.parse().unwrap()).collect::<Vec<u32>>();
    let cnt = merge_sort(&mut series, 0, n);

    println!("{}", cnt);
}

// 反転数をreturnするようになってる
fn merge<T: Ord + Clone>(series: &mut Vec<T>, left: usize, mid: usize, right: usize) -> u64 {
    let ls = series[left..mid].to_vec();
    let rs = series[mid..right].to_vec();

    let mut inv_cnt = 0;
    let mut li = 0;
    let mut ri = 0;
    for i in left..right {
        if ls.len() <= li {
            series[i] = rs[ri].clone();
            ri += 1;            
        } else if rs.len() <= ri {
            series[i] = ls[li].clone();
            li += 1;
        } else if ls[li] > rs[ri] {
            series[i] = rs[ri].clone();
            ri += 1;
            inv_cnt += ls.len() - li; // 反転数を数えている
        } else {
            series[i] = ls[li].clone();
            li += 1;
        }
    }
    return inv_cnt as u64;
}

// 反転数をreturnするようになってる
fn merge_sort<T: Ord + Clone>(series: &mut Vec<T>, left: usize, right: usize) -> u64 {
    if left + 1 < right {
        let mid = (left + right) / 2;
        let c1 = merge_sort(series, left, mid);
        let c2 = merge_sort(series, mid, right);
        let c3 = merge(series, left, mid, right);
        return c1 + c2 + c3;
    } else {
        return 0;
    }
}