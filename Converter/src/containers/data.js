let data = {
    "kg": {"g": 1000,"mg": 1000000,"tonne": 1 / 1000},
    "g": {"kg": 1 / 1000,"mg": 1000,"tonne": 1 / 1000000},
    "mg": {"kg": 1 / 1000000,"g": 1 / 1000,"tonne": 1 / 1000000000},
    "tonne": {"kg": 1000,"g": 1000000,"mg": 1000000000},
    "second": { "milisecond": 1000, "minute": 1 / 60 },
    "milisecond": { "second": 1 / 1000, "minute": 1 / 60000 },
    "minute": { "milisecond": 60000, "second": 60 },
    "meter": { "kilometer": 1 / 1000, "santimeter": 100 },
    "kilometer": { "meter": 1000, "santimeter": 100000 },
    "santimeter": { "kilometer": 1 / 100000, "meter": 1 / 100 },
    // "Celsius": {"Kelvin":, "Farenhite":}, 
    // "Kelvin": {"Farenhite":, "Celsius":} 
}
export default data