fn read_lines() -> Vec<String> {
    use std::io::Read;

    let mut buf = String::new();
    std::io::stdin().read_to_string(&mut buf).unwrap();
    return buf.lines().map(|e| e.to_string()).collect::<Vec<_>>();
}

fn main() {
    let input = read_lines();
    let n: usize = input[0].parse().unwrap();
    let input_series: Vec<usize> = input[1].split_whitespace().map(|e| e.parse().unwrap()).collect::<Vec<usize>>();

    let max_series_element = 10_000;
    let mut counting: Vec<usize> = vec![0; max_series_element];
    for e in &input_series {
        counting[*e] += 1;
    }
    for i in 1..max_series_element {
        counting[i] += counting[i-1];
    }

    let mut output_series = vec![0; n];
    for j in (0..n).rev() {
        output_series[counting[input_series[j]]-1] = input_series[j];
        counting[input_series[j]] -= 1;
    }

    println!("{}", output_series.into_iter().map(|u| format!("{}", u)).collect::<Vec<_>>().join(" "));
}
