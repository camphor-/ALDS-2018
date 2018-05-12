#[cfg(test)]
mod tests {
    use sorts;
    #[test]
    fn check_insertion_sort() {
        let mut a: Vec<i32> = vec![5,2,4,6,1,3];
        let ans : Vec<i32> = vec![1,2,3,4,5,6];
        sorts::insertion_sort(&mut a,6);
        assert_eq!(a, ans);
    }

    #[test]
    fn check_bubble_sort() {
        let mut a: Vec<i32> = vec![5,2,4,6,1,3];
        let ans : Vec<i32> = vec![1,2,3,4,5,6];
        sorts::bubble_sort(&mut a,6);
        assert_eq!(a, ans);
    }

    #[test]
    fn check_selection_sort() {
        let mut a: Vec<i32> = vec![5,2,4,6,1,3];
        let ans : Vec<i32> = vec![1,2,3,4,5,6];
        sorts::selection_sort(&mut a,6);
        assert_eq!(a, ans);
    }

    #[test]
    fn check_shell_sort() {
        let mut a: Vec<i32> = vec![5,2,4,6,1,3];
        let ans : Vec<i32> = vec![1,2,3,4,5,6];
        sorts::shell_sort(&mut a,6);
        assert_eq!(a, ans);
    }
}

mod sorts {
    pub fn insertion_sort(a: &mut Vec<i32>, n: usize) {
        for i in 1..n {
            // i番目の要素に注目
            let v = a[i];
            let mut j = i;
            // i番目より前の要素とi番目の要素を順に比較し、
            // i番目の要素が移るべき場所を探す
            while j > 0 && a[j-1] > v {
                a[j] = a[j-1];
                j -= 1;
            }
            a[j] = v;
            println!("{:?}",a);
        }
    }

    pub fn bubble_sort(a: &mut Vec<i32>, n: usize) {
        let mut sorted = false;
        while !sorted {
            sorted = true;
            // 入力配列を後ろから順にみていく
            for j in (1..n).rev() {
                if a[j] < a[j-1] {
                    let tmp = a[j];
                    a[j] = a[j-1];
                    a[j-1] = tmp;
                    sorted = false;
                }
            }
        }
    }

    pub fn selection_sort(a: &mut Vec<i32>, n: usize) {
        for i in 0..n {
            let mut minj = i;
            // i番目以上の要素で最小のものの添字を探す
            for j in i..n {
                if a[j] < a[minj] {
                    minj = j;
                }
            }
            let tmp = a[i];
            a[i] = a[minj];
            a[minj] = tmp;
        }
    }

    pub fn shell_sort(a: &mut Vec<i32>, n: usize) {
        let i_sort = |a: &mut Vec<i32>, m, g| {
            for i in g..m {
                let v = a[i];
                let mut j = i;
                while j > g-1 && a[j-g] > v {
                    a[j] = a[j-g];
                    j -= g;
                }
                a[j] = v;
            }
        };

        // 正しくないかも
        let g = |i| (3_usize.pow(i as u32) + 2)/2;
        for i in (0..n).rev() {
            i_sort(a, n, g(i));
        }
    }
}
