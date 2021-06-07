import React from 'react';
import './Account.css';
import NavigationBar from '../NavigationBar/NavigationBar';
import { H4, H5, Card, Avatar, Switch } from 'ui-neumorphism';
import { withRouter } from 'react-router';

class Account extends React.Component {
    render () {
        const {dark, setMode} = this.props;
        return (
            <>
            {/* <Card rounded width={300} height={600} dark = {dark} className='account-card'> */}
                <H4 className='account-title' dark = {dark}>Acconut</H4>
                <div className = 'person' flat>
                    <Avatar
                        bgColor = 'brown'
                        size = '150'
                        className = 'profile-photo'
                        src='https://www.searchpng.com/wp-content/uploads/2019/02/Profile-PNG-Icon-715x715.png'
                    />
                    <H5 dark = {dark}>Anounymous</H5>
                </div>
                <Switch label = 'Dark mode' dark = {dark} className = 'mode-switcher' onChange = {(event) => {
                    if (dark === false) {
                        setMode(true);
                    } else {
                        setMode(false);
                    }
                }}/>
                {/* <NavigationBar selected={'Account'} dark = {dark}/> */}
            {/* </Card> */}
            </>
        )
    }
}

export default withRouter(Account);
