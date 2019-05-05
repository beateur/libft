import Foundation

class Atoi {
    func myAtoi(str: String) -> Int {
        var res = 0
        var flag = 1
        var index = 0
        let int_max = 2147483647
        let int_min = -2147483648

        // trim
        let content = [Character](str)
        while index < content.count {
            guard content[index] == " " else {
                break
            }
            index += 1
        }
        guard index < content.count else {
            return res
        }

        // handle flag
        if content[index] == "-" {
            flag = -1
            index += 1
        } else if content[index] == "+" {
            index += 1
        }

        while index < content.count {
            guard isDigit(char: content[index]) else {
                break
            }

            res = res * 10 + Int(String(content[index]))!

            if res >= int_max {
                if flag == 1 {
                    return int_max
                } else if res > int_max && flag == -1 {
                    return int_min
                }
            }

            index += 1
        }

        return flag * res
    }

    func isDigit(char: Character) -> Bool {
        return char >= "0" && char <= "9"
    }
}

var to_Atoi = Atoi()

// extension StringProtocol {
//
//     subscript(offset: Int) -> Element {
//         return self[index(startIndex, offsetBy: offset)]
//     }
//
//     subscript(_ range: CountableRange<Int>) -> SubSequence {
//         return prefix(range.lowerBound + range.count)
//             .suffix(range.count)
//     }
//     subscript(range: CountableClosedRange<Int>) -> SubSequence {
//         return prefix(range.lowerBound + range.count)
//             .suffix(range.count)
//     }
//
//     subscript(range: PartialRangeThrough<Int>) -> SubSequence {
//         return prefix(range.upperBound.advanced(by: 1))
//     }
//     subscript(range: PartialRangeUpTo<Int>) -> SubSequence {
//         return prefix(range.upperBound)
//     }
//     subscript(range: PartialRangeFrom<Int>) -> SubSequence {
//         return suffix(Swift.max(0, count - range.lowerBound))
//     }
// }
//
// extension LosslessStringConvertible {
//     var string: String { return String(self) }
// }
//
// extension BidirectionalCollection {
//     subscript(safe offset: Int) -> Element? {
//         guard !isEmpty, let i = index(startIndex, offsetBy: offset, limitedBy: index(before: endIndex)) else { return nil }
//         return self[i]
//     }
// }
//
// let test = "Hello USA 🇺🇸!!! Hello Brazil 🇧🇷!!!"
// print(test[safe: 10]!)  // "🇺🇸"
// print("\n")
// print(test[11])   // "!"
// print("\n")
// print(test[10...])   // "🇺🇸!!! Hello Brazil 🇧🇷!!!"
// print("\n")
// print(test[10..<12])   // "🇺🇸!"
// print("\n")
// print(test[10...12])   // "🇺🇸!!"
// print("\n")
// print(test[...10]) // "Hello USA 🇺🇸"
// print("\n")
// print(test[..<10]) // "Hello USA "
// print("\n")
// print(test.first!)// "H"
// print("\n")
// print(test.last!)// "!"
// print("\n")
// // Subscripting the Substring
//  print(test[...][...3])  // "Hell"
// print("\n")
// // Note that they all return a Substring of the original String.
// // To create a new String you need to add .string as follow
// print(test[10...].string)  // "🇺🇸!!! Hello Brazil 🇧🇷!!!"
var MDArray: [[String]] = [["blabla", "tamere", "2019-06-05 01:57"],["kaka", "pipi", "2019-02-01 02:57"],["plop", "tmaer", "2018-02-01 03:54"]]
var swapper = String()
print(MDArray)
// var test = "2001"
// var test2 = "2002"
//
// if (Int(test)! < Int(test2)!){
//   print(test)
// }

// print(MDArray)

for Multitab in MDArray {
  // print(Multitab[2])
  swapper.append(Multitab[2])
  swapper.append("\n")
}
// print(swapper)
// print(SwapTab)

// for tab in SwapTab {
//   swapper.append(tab)
//   swapper.append("\n")
// }


let carac = [Character](swapper)
// print(carac)
// print(SwapTab)
// to_Atoi.myAtoi(str: &SwapTab[2][1])

// print(to_Atoi.myAtoi(str: &swapper[swapper.index(swapper.startIndex, offsetBy: 5)]))
/*
// test des dates
*/

var save2 = String()
var annee = [Int]()
var mois = [Int]()
var jour = [Int]()
var heure = [Int]()
var minute = [Int]()
var i = 0

for char in carac {
  if (to_Atoi.isDigit(char: char)) {
    save2.append(char)
  }
  else {
    if (i % 5 == 0) {
      annee.append(to_Atoi.myAtoi(str: save2))
    }
    if ((i - 1) % 5 == 0) {
      mois.append(to_Atoi.myAtoi(str: save2))
    }
    if ((i - 2) % 5 == 0) {
      jour.append(to_Atoi.myAtoi(str: save2))
    }
    if ((i - 3) % 5 == 0) {
      heure.append(to_Atoi.myAtoi(str: save2))
    }
    if ((i - 4) % 5 == 0) {
      minute.append(to_Atoi.myAtoi(str: save2))
    }
    i += 1
    save2 = ""
  }
}

func SwapTabInt(tab: inout [Int], index1: Int, index2: Int) {
  var swap: Int
  swap = tab[index1]
  tab[index1] = tab[index2]
  tab[index2] = swap
}

func SwapTabTabInt(tab: inout [[String]], index1: Int, index2: Int) {
  var swap: [String]
  swap = tab[index1]
  tab[index1] = tab[index2]
  tab[index2] = swap
}

func isDeroissantSorted(tab: [Int]) -> Bool {
  var index = 0
  while index + 1 < tab.count {
    if (tab[index] < tab[index + 1]) {
      return false
    }
    index += 1
  }
  return true
}

print(annee)
print(mois)
print(jour)
print(heure)
print(minute)
while true {
  i = 0
  while (i + 1 < annee.count) {
    if (annee[i] < annee[i + 1]) {
      SwapTabInt(tab: &annee, index1: i, index2: i + 1)
      SwapTabTabInt(tab: &MDArray, index1: i, index2: i + 1)
    }
    else if (annee[i] == annee[i + 1]) {
      if (mois[i] < mois[i + 1]) {
        SwapTabInt(tab: &mois, index1: i, index2: i + 1)
        SwapTabTabInt(tab: &MDArray, index1: i, index2: i + 1)
      }
      else if (mois[i] == mois[i + 1]) {
        if (jour[i] < jour[i + 1]) {
          SwapTabInt(tab: &jour, index1: i, index2: i + 1)
          SwapTabTabInt(tab: &MDArray, index1: i, index2: i + 1)
        }
        else if (jour[i] == jour[i + 1]) {
          if (heure[i] < heure[i + 1]) {
            SwapTabInt(tab: &heure, index1: i, index2: i + 1)
            SwapTabTabInt(tab: &MDArray, index1: i, index2: i + 1)
          }
          else if (heure[i] == heure[i + 1]) {
            if (minute[i] < minute[i + 1]) {
              SwapTabInt(tab: &minute, index1: i, index2: i + 1)
              SwapTabTabInt(tab: &MDArray, index1: i, index2: i + 1)
            }
          }
        }
      }
    }
    i += 1
  }
  if (isDeroissantSorted(tab: annee) == true) {
    break
  }
}
print(annee)
print(mois)
print(jour)
print(heure)
print(minute)
print(MDArray)

// var date = [Date]()
// date.init(timeIntervalSinceNow: "")

/*
// test des dates
*/

// while i < SwapTab.count {
//     while j < SwapTab[i].count {
//       i += 1
//       j += 1
//     }
//     if (i < SwapTab.count - 1 && to_Atoi.myAtoi(str: SwapTab[i]) > to_Atoi.myAtoi(str: SwapTab[i + 1])) {
//       swapper = SwapTab[i]
//       SwapTab[i] = SwapTab[i + 1]
//       SwapTab[i + 1] = swapper
//       i = -1
//     }
//     i += 1
// }
// print(SwapTab)

// struct Trixtest {
//     var trix = [["blabla", "tamere", "2019-05-01 01:57"],["kaka", "pipi", "2019-04-01 01:57"],["plop", "tmaer", "2018-05-01 01:57"]]
//     var swp: String
//
//     subscript(row: Int, col: Int) -> String {
//       get {
//         assert(trix[row][col] != nil, "no found")
//         return trix[row][col]
//       }
//       set {
//         assert(trix[row][col] != nil, "no found 2")
//         swp = newValue
//       }
//     }
// }
//
// var utest = Trixtest()
// print(utest[0, 2])

// let singer = Singer()
// print(singer.member)
// var save = String()
// save.append(SwapTab[2][0])

// print(save)


// print(to_Atoi.myAtoi(str: SwapTab))

// subscript(index: Int) -> Int {
//   get {
//
//   }
//   set {
//
//   }
// }
