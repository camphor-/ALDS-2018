fn read_lines() -> Vec<String> {
    use std::io::Read;

    let mut buf = String::new();
    std::io::stdin().read_to_string(&mut buf).unwrap();
    return buf.lines().map(|e| e.to_string()).collect::<Vec<_>>();
}

static mut COMP_COUNT: u32 = 0;

fn main() {
    let input = read_lines();
    let n: usize = input[0].parse().unwrap();
    let mut series = input[1].split_whitespace().map(|s| s.parse().unwrap()).collect::<Vec<u32>>();

    merge_sort(&mut series, 0, n);

    println!("{}", series.into_iter().map(|e| format!("{}", e)).collect::<Vec<String>>().join(" "));
    unsafe {
        println!("{}", COMP_COUNT);
    }
}

fn merge_sort(series: &mut Vec<u32>, left: usize, right: usize) {
    if left + 1 < right {
        let mid = (left + right) / 2;
        merge_sort(series, left, mid);
        merge_sort(series, mid, right);
        merge(series, left, mid, right);
    }
}

fn merge(series: &mut Vec<u32>, left: usize, mid: usize, right: usize) {
    let mut ls = series[left..mid].to_vec();
    ls.push(std::u32::MAX);
    let mut rs = series[mid..right].to_vec();
    rs.push(std::u32::MAX);

    let mut li = 0;
    let mut ri = 0;
    for i in left..right {
        unsafe {
            COMP_COUNT += 1;
        }
        if ls[li] > rs[ri] {
            series[i] = rs[ri];
            ri += 1;
        } else {
            series[i] = ls[li];
            li += 1;
        }
    }
}