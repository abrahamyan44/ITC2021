import React from 'react';
import Icon from '@mdi/react'
import {
  mdiHome,
  mdiBell,
  mdiFood,
  mdiAccount,
  mdiChartLine,
} from '@mdi/js'
import {
  H4,
  Card,
  withResize,
  ToggleButton,
} from 'ui-neumorphism'

class FitnessAppScreen extends React.Component {
  constructor(props) {
    super(props);
    this.getIconProps = this.getIconProps.bind(this);
  }

  getIconProps(index) {
    return {
      size: this.props.selectedIndex === index ? 0.9 : 0.8,
      color: this.props.selectedIndex === index
        ? 'var(--primary)'
        : this.props.dark ? 'var(--white)' : 'var(--black)',
    };
  }

  render() {
    return (
      <Card
        rounded
        width={300}
        height={600}
        dark={this.props.dark}
        className={`fitness-app ${
          this.props.size === 'xs' ? 'fitness-app--small' : ''
        } overflow-hidden`}
      >
        <H4 style={{ fontWeight: '500', marginTop: '8px' }} dark={this.props.dark}>{this.props.title}</H4>
        {this.props.children}
        <div className='fitness-app-nav-bar'>
          <ToggleButton selected={this.props.selectedIndex === 0} dark={this.props.dark}>
            <Icon
              path={mdiHome}
              {...this.getIconProps(0)}
            />
          </ToggleButton>
          <ToggleButton selected={this.props.selectedIndex === 1} dark={this.props.dark}>
            <Icon
              path={mdiChartLine}
              size={0.8}
              {...this.getIconProps(1)}
            />
          </ToggleButton>
          <ToggleButton selected={this.props.selectedIndex === 2} dark={this.props.dark}>
            <Icon
              path={mdiFood}
              {...this.getIconProps(2)}
            />
          </ToggleButton>
          <ToggleButton selected={this.props.selectedIndex === 3} dark={this.props.dark}>
            <Icon
              path={mdiBell}
              {...this.getIconProps(3)}
            />
          </ToggleButton>
          <ToggleButton selected={this.props.selectedIndex === 4} dark={this.props.dark}>
            <Icon
              path={mdiAccount}
              {...this.getIconProps(4)}
            />
          </ToggleButton>
        </div>
      </Card>
    );
  }
}

FitnessAppScreen.defaultProps = {
  size: 'xs',
  selectedIndex: 0,
};

export default withResize(FitnessAppScreen);
