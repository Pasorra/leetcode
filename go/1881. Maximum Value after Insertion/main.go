package main

func maxValue(n string, x int) string {
	place := len(n)
	if n[0] != '-' {
		for i := len(n) - 1; i >= 0; i-- {
			if int(n[i]-'0') < x {
				place = i
			}
		}
	} else {
		for i := len(n) - 1; i >= 1; i-- {
			if int(n[i]-'0') > x {
				place = i
			}
		}
	}
	return n[:place] + string(x+'0') + n[place:]
}

func main() {
	println(maxValue("-132", 3))
}
