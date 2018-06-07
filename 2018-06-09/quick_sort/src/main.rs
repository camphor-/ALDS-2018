fn read_string() -> String {
    use std::io::Read;

    let mut buf = String::new();
    std::io::stdin().read_to_string(&mut buf).unwrap();
    return buf;
}

fn swap<T: Clone>(series: &mut Vec<T>, i: usize, j: usize) {
    let tmp = series[i].clone();
    series[i] = series[j].clone();
    series[j] = tmp;
}

fn partition<T: Ord + Clone>(series: &mut Vec<T>, p: usize, r: usize) -> usize {
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

#[derive(Debug, Clone, Eq, PartialEq)]
struct Card {
    pub number: u32,
    pub design: String
}

impl Ord for Card {
    fn cmp(&self, other: &Self) -> std::cmp::Ordering {
        self.number.cmp(&other.number)
    }
}

impl PartialOrd for Card {
    fn partial_cmp(&self, other: &Self) -> Option<std::cmp::Ordering> {
        Some(self.cmp(other))
    }
}

fn quick_sort<T: Ord + Clone>(series: &mut Vec<T>, p: usize, r: usize) {
    if p < r {
        let q = partition(series, p, r);
        quick_sort(series, p, q-1);
        quick_sort(series, q+1, r);
    }
}

fn main() {
    let input = read_string();
    let input = input.lines().collect::<Vec<_>>();
    let n: usize = input[0].parse().unwrap();
    let cards = input[1..n+1].iter().map(|line| {
        let es = line.split_whitespace().collect::<Vec<_>>();
        Card {
            number: es[1].parse().unwrap(),
            design: es[0].to_string()
        }
    }).collect::<Vec<_>>();
    let mut cards_quick = cards.clone();
    quick_sort(&mut cards_quick, 0, n-1);
    let mut cards_merge = cards.clone();
    merge_sort(&mut cards_merge, 0, n);

    if cards_quick == cards_merge {
        println!("Stable");
    } else {
        println!("Not stable");
    }

    for card in cards_quick {
        println!("{} {}", card.design, card.number);
    }
}

fn merge<T: Ord + Clone>(series: &mut Vec<T>, left: usize, mid: usize, right: usize) {
    let ls = series[left..mid].to_vec();
    let rs = series[mid..right].to_vec();

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
        } else {
            series[i] = ls[li].clone();
            li += 1;
        }
    }
}

fn merge_sort<T: Ord + Clone>(series: &mut Vec<T>, left: usize, right: usize) {
    if left + 1 < right {
        let mid = (left + right) / 2;
        merge_sort(series, left, mid);
        merge_sort(series, mid, right);
        merge(series, left, mid, right);
    }
}