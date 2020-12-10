#!/usr/bin/python3


def canUnlockAll(boxes):
    keysForBoxes = [0]
    indexBoxesOpened = [0]
    haveKeys = True

    while haveKeys:
        haveKeys = False
        for box in boxes:
            if boxes.index(box) in keysForBoxes:
                if boxes.index(box) not in indexBoxesOpened:
                    indexBoxesOpened.append(boxes.index(box))
                for key in box:
                    if key not in keysForBoxes:
                        keysForBoxes.append(key)
                        haveKeys = True

    if len(indexBoxesOpened) == len(boxes):
        return True
    else:
        return False
