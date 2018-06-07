fn swap<T: Clone>(series: &mut Vec<T>, i: usize, j: usize) {
    let tmp = series[i].clone();
    series[i] = series[j].clone();
    series[j] = tmp;
}

fn partition<T: Ord + Clone + std::fmt::Debug>(series: &mut Vec<T>, p: usize, r: usize) -> usize {
    let x = series[r].clone();
    let mut i = p;
    for j in p..r {
        if series[j] <= x {
            swap(series, i, j);
            i += 1;
        }
    }
    swap(series, i, r);
    return i;
}

fn main() {
    let input = read_string();
    let input = input.lines().collect::<Vec<_>>();
    let n: usize = input[0].parse().unwrap();
    let r = n - 1;
    let mut series = input[1].split_whitespace().map(|e| e.parse().unwrap()).collect::<Vec<u32>>();

    let q = partition(&mut series, 0, r);

    let small = series[0..q].iter().map(|e| format!("{}", e)).collect::<Vec<String>>().join(" ");
    let large = series[q+1..r+1].iter().map(|e| format!("{}", e)).collect::<Vec<String>>().join(" ");
    println!("{} [{}] {}", small, series[q], large);
}

fn read_string() -> String {
    use std::io::Read;

    let mut buf = String::new();
    std::io::stdin().read_to_string(&mut buf).unwrap();
    return buf;
}
