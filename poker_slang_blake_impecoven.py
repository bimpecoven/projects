# Blake Impecoven - Poker - 5/27/2014


from Card import *

def main():
    handCount = intInput("Enter number of hands: ")


    #
    # initialize accumulator variables for each hand scoring category
    # (Straight Flush, 4 of a Kind, Full House, Flush, Straight, 3 of a Kind, 2 Pair, 1 Pair, High Card)
    sf = 0
    foak = 0
    fh = 0
    f = 0
    s = 0
    toak = 0
    tp = 0
    op = 0
    hc = 0


    # Loop for number of hands
    try:
        for ctr in range(handCount):
            #
            # Draw Hand - returned hand is in rank sorted order
            hand = DrawHand()


            #
            # Send hand to scoring methods, increment accumulator vars for each hand type
            # You can check a card's rank with hand[ix].rank and the suit with hand[ix].suit
            if isStraightFlush(hand) == True:
                sf += 1
            elif isFourOfAKind(hand) == True:
                foak += 1
            elif isFullHouse(hand) == True:
                fh += 1
            elif isFlush(hand) == True:
                f += 1
            elif isStraight(hand) == True:
                s += 1
            elif isThreeOfAKind(hand) == True:
                toak += 1
            elif isTwoPair(hand) == True:
                tp += 1
            elif isOnePair(hand) == True:
                op += 1
            else:
                hc += 1
    except:
        return None
        print("Error! Invalid Input!")



    print("Total number of Hands Drawn: ", handCount)
    print()
    print("Straight Flush: ", sf, "(", "{0:.4f}".format(sf / handCount), "%)")
    print("Four of a Kind: ", foak, "(", "{0:.4f}".format(foak / handCount), "%)")
    print("Full House: ", fh, "(", "{0:.4f}".format(fh / handCount), "%)")
    print("Flush: ", f, "(", "{0:.4f}".format(f / handCount), "%)")
    print("Straight: ", s, "(", "{0:.4f}".format(s / handCount), "%)")
    print("Three of a Kind: ", toak, "(", "{0:.4f}".format(toak / handCount), "%)")
    print("Two Pair: ", tp, "(", "{0:.4f}".format(tp / handCount), "%)")
    print("One Pair: ", op, "(", "{0:.4f}".format(op / handCount), "%)")
    print("High Card: ", hc, "(", "{0:.4f}".format(hc / handCount), "%)")

    # Write the above results to a file
    try:
        poker_results = open('results.txt', 'w')

        poker_results.write("Total number of Hands Drawn: ") #total
        poker_results.write(str(handCount) + "\n")
        poker_results.write("\n")

        poker_results.write("Straight Flush: ") #Straight Flush
        poker_results.write(str(sf))
        poker_results.write("(")
        poker_results.write("{0:.4f}".format(sf / handCount))
        poker_results.write("%)\n")

        poker_results.write("Four of a Kind: ") #Four of a kind
        poker_results.write(str(foak))
        poker_results.write("(")
        poker_results.write("{0:.4f}".format(foak / handCount))
        poker_results.write("%)\n")

        poker_results.write("Full House: ") #Full House
        poker_results.write(str(fh))
        poker_results.write("(")
        poker_results.write("{0:.4f}".format(fh / handCount))
        poker_results.write("%)\n")

        poker_results.write("Flush: ") #Flush
        poker_results.write(str(f))
        poker_results.write("(")
        poker_results.write("{0:.4f}".format(f / handCount))
        poker_results.write("%)\n")

        poker_results.write("Straight: ") #Straight
        poker_results.write(str(s))
        poker_results.write("(")
        poker_results.write("{0:.4f}".format(s / handCount))
        poker_results.write("%)\n")

        poker_results.write("Three of a Kind: ") #Three of a kind
        poker_results.write(str(toak))
        poker_results.write("(")
        poker_results.write("{0:.4f}".format(toak / handCount))
        poker_results.write("%)\n")

        poker_results.write("Two Pair: ") #Two pair
        poker_results.write(str(tp))
        poker_results.write("(")
        poker_results.write("{0:.4f}".format(tp / handCount))
        poker_results.write("%)\n")

        poker_results.write("One Pair: ") #One pair
        poker_results.write(str(op))
        poker_results.write("(")
        poker_results.write("{0:.4f}".format(op / handCount))
        poker_results.write("%)\n")

        poker_results.write("High Card: ") #High card
        poker_results.write(str(hc))
        poker_results.write("(")
        poker_results.write("{0:.4f}".format(hc / handCount))
        poker_results.write("%)\n")

        poker_results.close
        print("Success!")
    except:
        pass
        print("Error!")
        print("Couldn't write 'results.txt'")


def DrawHand():
    # randomly draw hand, insure not duplicates, returns hand

    deck = []
    for i in range(52):
        potential = Card()
        while potential in deck:
            potential = Card()
        deck.append(potential)

    hnd = deck[0:5]
    hnd.sort(key=cardKey)
    return hnd

def cardKey(cd):
    return cd.rank



def isStraightFlush(hand):
    if isFlush(hand) and isStraight(hand):
        return True
    else:
        return False

def isFourOfAKind(hand):
    if hand[0].rank == hand[1].rank and hand[0].rank == hand[2].rank and hand[0].rank == hand[3].rank:
        return True
    elif hand[1].rank == hand[2].rank and hand[1].rank == hand[3].rank and hand[1].rank == hand[4].rank:
        return True
    else:
        False

def isFullHouse(hand):
    if hand[0].rank == hand[1].rank and hand[0].rank == hand[2].rank and hand[3].rank == hand[4].rank:
        return True
    elif hand[2].rank == hand[3].rank and hand[2].rank == hand[4].rank and hand[0].rank == hand[1].rank:
        return True
    else:
        return False

def isFlush(hand):
    if hand[0].suit == hand[1].suit and hand[0].suit == hand[2].suit and hand[0].suit == hand[3].suit and hand[0].suit == hand[4].suit:
        return True
    else:
        return False

def isStraight(hand):
    if hand[0].rank == hand[1].rank - 1 and hand[1].rank == hand[2].rank - 1 and hand[2].rank == hand[3].rank - 1 and hand[3].rank == hand[4].rank - 1:
        return True
    else:
        return False

def isThreeOfAKind(hand):
    if hand[0].rank == hand[1].rank and hand[0].rank == hand[2].rank:
        return True
    elif hand[2].rank == hand[3].rank and hand[2].rank == hand[4].rank:
        return True
    else:
        return False

def isTwoPair(hand):
    if hand[0].rank == hand[1].rank and hand[2].rank == hand[3].rank:
        return True
    elif hand[0].rank == hand[1].rank and hand[3].rank == hand[4].rank:
        return True
    elif hand[2].rank == hand[3].rank and hand[3].rank == hand[4].rank:
        return True
    else:
        return False

def isOnePair(hand):
    if hand[0].rank == hand[1].rank:
        return True
    elif hand[1].rank == hand[2].rank:
        return True
    elif hand[2].rank == hand[3].rank:
        return True
    elif hand[3].rank == hand[4].rank:
        return True
    else:
        return False

#-----------------------------------------------
def writeResults(file):
    file.write("Total number of Hands Drawn: ", handCount/n)
    file.write('/n')
    file.write("Straight Flush: ", sf, "(", "{0:.4f}".format(sf / handCount), "%)/n")
    file.write("Four of a Kind: ", foak, "(", "{0:.4f}".format(foak / handCount), "%)/n")
    file.write("Full House: ", fh, "(", "{0:.4f}".format(fh / handCount), "%)/n")
    file.write("Flush: ", f, "(", "{0:.4f}".format(f / handCount), "%)/n")
    file.write("Straight: ", s, "(", "{0:.4f}".format(s / handCount), "%)/n")
    file.write("Three of a Kind: ", toak, "(", "{0:.4f}".format(toak / handCount), "%)/n")
    file.write("Two Pair: ", tp, "(", "{0:.4f}".format(tp / handCount), "%)/n")
    file.write("One Pair: ", op, "(", "{0:.4f}".format(op / handCount), "%)/n")
    file.write("High Card: ", hc, "(", "{0:.4f}".format(hc / handCount), "%)/n")
    return file

def intInput(prompt):
        try:
            handCount = int(input(prompt))
            return handCount
        except:
            pass
            print("Not a valid number of hands!")
            print("Enter an Integer...")

main()


