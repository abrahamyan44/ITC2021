import React from 'react';
import { Card, CardContent, IconButton } from 'ui-neumorphism';
import { Link } from "react-router-dom";
import Icon from '@mdi/react';
import {
    mdiHome,
    mdiChartLine,
    mdiBell,
    mdiAccount,
    mdiHamburger
} from '@mdi/js';
import './Navigation.css';


function Navigation(props) {

    return (
        <Card className='navigation' width={340} height={60}>
            <CardContent className='card-content'>
                <IconButton size='small'>
                    <Link to="/program">
                        <Icon path={mdiHome} size={1.2} />
                    </Link>
                </IconButton>
                <IconButton size='small'>
                    <Link to="/planlist">
                        <Icon path={mdiChartLine} size={1.2} />
                    </Link>
                </IconButton>
                <IconButton size='small'>
                    <Link to="/food">
                        <Icon path={mdiHamburger} size={1.2} />
                    </Link>
                </IconButton>
                <IconButton size='small' >
                    <Link to="/notification">
                        <Icon path={mdiBell} size={1.2} />
                    </Link>
                </IconButton>
                <IconButton size='small'>
                    <Link to="/profile">
                        <Icon path={mdiAccount} size={1.2} />
                    </Link>
                </IconButton>
            </CardContent>
        </Card>
    )
}

export default Navigation;
