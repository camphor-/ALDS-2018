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
    let r = n - 1;

    let q = partition(&mut series, 0, r);

    let small = series[0..q].iter().map(|e| format!("{}", e)).collect::<Vec<String>>().join(" ");
    let large = series[q+1..r+1].iter().map(|e| format!("{}", e)).collect::<Vec<String>>().join(" ");
    println!("{} [{}] {}", small, series[q], large);
}

fn partition<T: Ord + Clone>(series: &mut Vec<T>, p: usize, r: usize) -> usize {
    let x = series[r].clone();
    let mut i = (p as i64) - 1;
    for j in p..r {
        if series[j] <= x {
            swap(series, (i + 1) as usize, j);
            i += 1;
        }
    }
    swap(series, (i + 1) as usize, r);
    return (i + 1) as usize;
}

fn swap<T: Clone>(series: &mut Vec<T>, i: usize, j: usize) {
    let tmp = series[i].clone();
    series[i] = series[j].clone();
    series[j] = tmp;
}