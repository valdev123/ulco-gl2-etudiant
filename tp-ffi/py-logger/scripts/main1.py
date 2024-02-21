import Logger as l

if __name__ == '__main__':

    print('TODO')

    # TODO create a logger and add some items
    logger = l.Logger()
    logger.add_item(l.Level.Info,"une info")
    logger.add_item(l.Level.Error,"une erreur")
    logger.add_item(l.Level.Info,"une autre info")
    logger.add_item(l.Level.Warning,"un avertissement")
    

    # TODO report_by_added
    print(logger.report_by_added())

    # TODO report_by_level
    print(logger.report_by_level())

