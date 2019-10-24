month = int(input())
date = int(input())

dates = (21, 20, 21, 21, 22, 22, 23, 24, 24, 24, 23, 22)
constellations = ("Capricorn", "Aquarius", "Pisces", "Aries", "Taurus", "Gemini", "Cancer", "Leo", "Virgo", "Libra", "Scorpio", "Sagittarius", "Capricorn")
if date < dates[month-1]:
    print (constellations[month-1])
else:
    print (constellations[month])