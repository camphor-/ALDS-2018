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
}

