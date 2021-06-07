let obj = [
  {
    id: 0,
    value: {
      "second": ["milisecond", "minute"], "milisecond": ["second", "minute"],
      "minute": ["milisecond", "second"]
    },
    selectOp: document.createElement("select")
  },
  {
    id: 1,
    value: { "kg": ["g", "mg", "tonne"], "g": ["mg", "tonne", "kg"], "mg": ["tonne", "kg", "g",], "tonne": ["kg", "g", "mg"] },
    selectOp: document.createElement("select")
  },
  {
    id: 2,
    value: {
      "meter": ["kilometer", "santimeter"], "kilometer": ["meter", "santimeter"],
      "santimeter": ["kilometer", "meter"]
    },
    selectOp: document.createElement("select")
  },
]

export default obj;